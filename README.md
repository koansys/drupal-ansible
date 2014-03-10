drupal-ansible
==============

An Ansible playbook for a Drupal installation on Ubuntu.

Virtualenv
----------

Some folks like other variants like pyenv, I'm old-school.

    virtualenv . --no-site-packages --distribute
    source bin/activate
    pip install -r requirements.txt

After creating instance, test authentication
--------------------------------------------

Substitue your instance's public DNS name of course:

    ssh -v -i ~/path/to/yourkey.pem ec2-user@ec2-107-20-89-160.compute-1.amazonaws.com


Inventory (host) file
---------------------

If you've got (say) your dev hosts in hosts/dev, you can specify variable to apply:

    [gluster-brick-1]
    ec2-107-20-89-160.compute-1.amazonaws.com ansible_ssh_user=ec2-user


Then you can connect and run a command like 'hostname':

    ansible -a hostname -i hosts/dev gluster-brick-1 --private-key=~/path/to/instance-key.pem 

You'll need to add all your users private keys to that account, or
better, add accounts with private keys for each user. Best to create a playbook for this.


Tasks
-----

Add new task:

    $ mkdir -p roles/TASK_NAME/{tasks,handlers,templates,files,vars}
    $ touch roles/TASK_NAME/tasks/main.yml

Run Playbook
------------

To run:

* creates initial machine (and database)

        $ ansible-playbook -i hosts/seed playbooks/drupal-bootstrap.yml -K

* creates subsequent machines (when database already exists)

        $ ansible-playbook i hosts/production playbooks/drupal-bootstrap.yml --skip-tags "init" -K

* creates read-only consumer boxes.

        $ ansible-playbook i hosts/production playbooks/drupal-bootstrap.yml --skip-tags "init" -K
        $ ansible-playbook -i hosts/production playbooks/drupal-readonly.yml -K

Chris does things more complicated, specifying his key:

    $ ansible-playbook -v -i hosts/dev playbooks/create-gluster.yml --private-key=~/AeroFS/AWS-keys/chriskoansys.pem

Using Vagrant
-------------

* Install Vagrant (v1.4.3 at current)
* Install Vagrant-HostsUpdater plugin: `vagrant plugin install vagrant-hostsupdater`
* Startup Vagrant: `vagrant up`

Then run ansible to bootstrap drupal:

  ansible-playbook -i hosts/vagrant -v playbooks/drupal-boostrap.yml -K
