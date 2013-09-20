--TEST--
ACL inheritance is broken in 1.2.X - https://github.com/phalcon/cphalcon/issues/905
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$acl = new \Phalcon\Acl\Adapter\Memory();

$acl->setDefaultAction(\Phalcon\Acl::DENY);

$acl->addRole('user');
$acl->addRole('admin', 'user');
$acl->addRole('developer', 'admin');

$acl->addResource('tickets', array('list', 'open', 'close'));

$acl->allow('user', 'tickets', 'open');

var_dump((int)$acl->isAllowed('user', 'tickets', 'open'));
var_dump((int)$acl->isAllowed('admin', 'tickets', 'open'));
var_dump((int)$acl->isAllowed('developer', 'tickets', 'open'));
?>
--EXPECT--
int(1)
int(1)
int(1)
