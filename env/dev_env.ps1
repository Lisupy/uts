docker-compose -f ./dockerfile/docker-compose.yml up -d
docker exec -it uts_dev /bin/bash
docker-compose -f ./dockerfile/docker-compose.yml down