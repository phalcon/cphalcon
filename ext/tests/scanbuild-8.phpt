--TEST--
Dereference of null pointer in zim_Phalcon_Security_deriveKey()
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
\Phalcon\Security::deriveKey('password', 'sa;t');
?>
--EXPECT--
