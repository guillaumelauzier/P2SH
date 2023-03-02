# P2SH

Pay-to-Script-Hash (P2SH) is a type of transaction output script used in Bitcoin to enable more flexible spending conditions. With P2SH, instead of directly locking the funds to a public key or a script, the funds are locked to a hash of a redeem script. The redeem script is a more complex script that specifies the conditions that must be met to spend the funds.

When a P2SH output is spent, the spender must provide a script that satisfies the conditions specified in the redeem script. The hash of the redeem script is used as the locking script for the output, and the spender provides the actual redeem script in the input of the spending transaction.

P2SH was introduced in 2012 as part of Bitcoin Improvement Proposal (BIP) 16, and it has since become a widely used feature in the Bitcoin protocol. It has enabled a variety of use cases such as multisignature transactions, atomic swaps, and lightning network channels.

# src.cpp

This code defines a P2SH output script that pays to a specific public key hash. It first defines the inner script using the bc::script::to_pay_key_hash_pattern method, which creates a script that pays to a specific public key hash. It then hashes this script using the SHA256 and RIPEMD160 hash functions to obtain a short hash.

Next, it creates a P2SH script by prefixing the short hash with the P2SH prefix 0x05, and creating a new script using this data. The resulting P2SH script can be included as the output script in a Bitcoin transaction, and the funds can be redeemed by providing the redeem script (the original inner script in this case) along with a signature that satisfies the conditions of the script.
