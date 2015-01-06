--TEST--
Negating ACL roles - https://github.com/phalcon/cphalcon/issues/65
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$acl = new \Phalcon\Acl\Adapter\Memory();
$acl->setDefaultAction(\Phalcon\Acl::DENY);

$acl->addRole('Guests');
$acl->addRole('Members', 'Guests');

$acl->addResource('Login', array('index'));

$acl->allow('Guests', 'Login', 'index');
$acl->deny('Members', 'Login', 'index');
var_dump((bool)$acl->isAllowed('Members', 'Login', 'index'));
?>
--EXPECT--
bool(false)
