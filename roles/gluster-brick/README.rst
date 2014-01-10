Gluster Brick holds raw storage and exports it to "Gluster Client".

Need 1GB RAM for testing, minimum 8GB RAM for production.
m1.xlarge=15GiB,4x420GiB
m2.xlarge=17Gib,1x420Gib
m2.2xlarge=34Gib,1x850 (EBS-opt avail)

We use at least 2 bricks for redundancy. These are mounted by all the
webapp servers for Drupal /files/*.  While we could have the brick
(storage) on the webapps, those are expected to be auto-scaling and I
am concerned that at instance creation time that any brick storage
would take a long time to synchronize with extant nodes -- simply
copying 1TB data. So we separate replicated storage from auto-scaling
clients.

For testing, we're using Ubuntu on m1.small with 100GB added EBS on
/dev/sdb, destroyed on termination. Both in VPC, in US-East-1b and
-1d.



