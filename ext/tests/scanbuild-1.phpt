--TEST--
Branch condition evaluates to a garbage value - zim_Phalcon_Db_Column___set_state
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$data = array('_isNumeric' => true, '_columnName' => 'column', '_type' => 'integer');
\Phalcon\Db\Column::__set_state($data);
?>
--EXPECT--
