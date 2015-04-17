--TEST--
Dereference of null pointer in zim_Phalcon_Acl_Adapter_Memory_dropResourceAccess
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$a = new \Phalcon\Acl\Adapter\Memory();
$a->dropResourceAccess('resource', 'accesslist');
?>
--EXPECT--
