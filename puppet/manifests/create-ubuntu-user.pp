user { "ubuntu":
  groups => 'admin',
  comment => 'Ubuntu Sudo User',
  home => '/home/ubuntu',
  shell => '/bin/bash',
  ensure => present,
  managehome => true,
}

file { "/home/ubuntu/.ssh":
  ensure        => directory,
  owner          => 'ubuntu',
  group         => 'ubuntu',
  mode          => 0600,
}

file { "/home/ubuntu/.ssh/authorized_keys":
  ensure        => present,
  owner          => 'ubuntu',
  group         => 'ubuntu',
  mode          => 0600,
  # Can't figure out how to push local file to server
  # Vagrantfile defines 'modules_path' to ./vagrant/modules
  # Puppet looks for file under modules_path/ssh/*files*/authorized_keys
  source => "puppet:///modules/ssh/authorized_keys",
  require       => [User['ubuntu'], File['/home/ubuntu/.ssh']],
}
