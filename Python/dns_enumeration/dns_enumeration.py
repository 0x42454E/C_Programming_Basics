from time import sleep

import dns.resolver

target_domain = "infinitylaboratories.com"

with open('words.csv', 'r') as f:
    record_types = f.readlines()
    record_types = [line.strip() for line in record_types]

resolver = dns.resolver.Resolver()

for record_type in record_types:
    try:
        answers = resolver.resolve(target_domain, record_type)
        for rdata in answers:
            print(f"{record_type}.{target_domain} -> {rdata.address}")
        #Process answers
    except:
        continue




