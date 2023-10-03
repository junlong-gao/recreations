## Setup

- Install homebrew
- Install [gcloud](https://cloud.google.com/sdk/docs/install)

## Common Command

List instance
```
gcloud compute instances list
NAME     ZONE        MACHINE_TYPE   PREEMPTIBLE  INTERNAL_IP  EXTERNAL_IP     STATUS
default  us-west1-b  c2-standard-8               10.138.0.2   35.233.239.225  RUNNING
```

Inspect instance
```
gcloud compute instances describe default
```

Shutdown instance
```
gcloud compute instances stop default
```

Get external ip
```
gcloud compute instances describe default \
  --format='get(networkInterfaces[0].accessConfigs[0].natIP)'
```

### Install SSH Config
```
ln -fs $(pwd)/config ~/.ssh/
```