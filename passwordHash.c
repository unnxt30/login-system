#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

// memcpy() is used to copy a block of memory from a location to another. It is declared in string.h

/* RAND_bytes() puts num cryptographically strong pseudo-random bytes into buf. An error occurs if the PRNG has not been seeded with
enough randomness to ensure an unpredictable byte sequence. */ 

void hash_password(char *password, char *hash, char *salt) {
    
    // Generate a random salt
    unsigned char rand_salt[32];
    RAND_bytes(rand_salt, 32);
    memcpy(salt, rand_salt, 32);

    // Concatenate salt and password
    unsigned char concat[strlen(password) + 32];
    memcpy(concat, salt, 32); //copies salt into concat.
    memcpy(concat + 32, password, strlen(password)); //copies the password into concat.

    printf("The salted passwd is: %s\n", concat);

    //concat now contains the password as well as the salt.

    // Hash the concatenated string
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len;
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    md = EVP_sha256();
    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, concat, strlen(password) + 32);
    EVP_DigestFinal_ex(mdctx, md_value, &md_len);
    EVP_MD_CTX_free(mdctx);

    // Convert the hashed password to hex
    char hex_hash[2*md_len+1];
    for(int i = 0; i < md_len; i++) {
        sprintf(hex_hash + 2*i, "%02x", md_value[i]);
    }
    memcpy(hash, hex_hash, 2*md_len+1);
}

int verify_password(char *password, char *hash, char *salt) {
    // Concatenate salt and password
    unsigned char concat[strlen(password) + 32];
    memcpy(concat, salt, 32);
    memcpy(concat + 32, password, strlen(password));

    // Hash the concatenated string
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len;
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    md = EVP_sha256();
    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, concat, strlen(password) + 32);
    EVP_DigestFinal_ex(mdctx, md_value, &md_len);
    EVP_MD_CTX_free(mdctx);

    // Convert the hashed password to hex
    char hex_hash[2*md_len+1];
    for(int i = 0; i < md_len; i++) {
        sprintf(hex_hash + 2*i, "%02x", md_value[i]);
    }

    // Compare the hashed password with the stored hash
    if (strcmp(hex_hash, hash) == 0) {
        return 1; // Passwords match
    } else {
        return 0; // Passwords don't match
    }
}

int main() {
    char password[] = "mypassword";
    char hash[65];
    char salt[33];
    hash_password(password, hash, salt);
    printf("Hash: %s\nSalt: %s\n", hash, salt);

    // Verify the password
    if (verify_password("mypassword", hash, salt)) {
        printf("Password is correct!\n");
    } else {
        printf("Password is incorrect!\n");
    }

    return 0;
}
