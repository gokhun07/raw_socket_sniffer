#include "ip_packets.hh"
#include "../process-packet/process_packet.hh"
#include "../log/log.hh"


PROTOCOL_HEADER get_ip_protocol(const char *buf, std::size_t size)
{
    struct iphdr *iph = (struct iphdr*)buf;
    
    switch (iph->protocol)
    {
        case 1: // ICMP Protocol
            return (PROTOCOL_HEADER::ICMP);
        break;
        default:
            break;
    }
    return (PROTOCOL_HEADER::NO_PROTO);

}

void get_source_and_target_ip(const char *buf, std::size_t size, std::vector<unsigned char>& src,std::vector<unsigned char>& dest)
{
    struct iphdr *iph = (struct iphdr*)buf;

    for (std::uint32_t loop_counter = 0; loop_counter  < 4; loop_counter++)
    {
        src.push_back((unsigned char)(iph->saddr >> (loop_counter*8)) & 0xFF);
        dest.push_back((unsigned char)(iph->daddr >> (loop_counter*8)) & 0xFF);
    }
}

ip_packets::ip_packets(/* args */)
{
}

ip_packets::~ip_packets()
{
}
