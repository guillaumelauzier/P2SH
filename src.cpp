#include <bitcoin/bitcoin.hpp>

int main() {
    // Define the script that will be hashed
    bc::script inner_script = bc::script::to_pay_key_hash_pattern(bc::wallet::ec_public("023f483316ab0d0c8af3d90081ee90a92f925f9b9aa30d9a2c2fa3421b78705e34"));

    // Hash the inner script
    bc::short_hash hash = bc::bitcoin_short_hash(inner_script.to_data());

    // Create the P2SH script
    bc::data_chunk p2sh_data;
    p2sh_data.push_back(0x05); // P2SH prefix
    p2sh_data.insert(p2sh_data.end(), hash.begin(), hash.end());
    bc::script p2sh_script(bc::to_chunk(p2sh_data));

    // Output the P2SH script
    std::cout << "P2SH Script: " << p2sh_script.to_string() << std::endl;

    return 0;
}
