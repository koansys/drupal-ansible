drupal-ansible
==============

An Ansible playbook for a Drupal installation on Ubuntu.


Add new task:

    $ mkdir -p roles/TASK_NAME/{tasks,handlers,templates,files,vars}
    $ touch roles/TASK_NAME/tasks/main.yml

To run:
- creates Content Editors
    $ ansible-playbook -i production bootstrap.yml -K
    $ ansible-playbook -i production cleanup.yml -K

- creates Content Editors
    $ ansible-playbook -i production bootstrap.yml -K
    $ ansible-playbook -i production cleanup.yml -K
    $ ansible-playbook -i production readonly.yml -K
