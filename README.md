drupal-ansible
==============

An Ansible playbook for a Drupal installation on Ubuntu.

Virtualenv
----------

Some folks like other variants like pyenv, I'm old-school::

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

    $ ansible-playbook -i stage bootstrap.yml -K

Chris does things more complicated, specifying his key:

    $ ansible-playbook -v -i hosts/dev create-gluster.yml --private-key=~/AeroFS/AWS-keys/chriskoansys.pem