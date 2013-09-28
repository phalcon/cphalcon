--TEST--
ACL allows access to forbidden resources - https://github.com/phalcon/cphalcon/issues/1303
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$acl = new \Phalcon\Acl\Adapter\Memory();

$acl->setDefaultAction(\Phalcon\Acl::DENY);

$acl->addRole('Guests');
$acl->addRole('Designers');

$customersResource = new \Phalcon\Acl\Resource('Customers', 'Customers management');

$acl->addResource($customersResource, array('search', 'create', 'update'));

$acl->allow('Guests', 'Customers', 'search');
$acl->allow('Guests', 'Customers', 'create');
$acl->deny('Guests', 'Customers', 'update');

var_dump((int)$acl->isAllowed('Guests', 'Customers', 'edit'));
var_dump((int)$acl->isAllowed('Guests', 'Customers', 'update'));
?>
--EXPECT--
int(0)
int(0)
