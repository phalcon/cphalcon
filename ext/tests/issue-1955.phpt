--TEST--
Phalcon\Forms\Element\Select::addOption() does not work - Fix Phalcon\Forms\Element\Select::addOption()
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
new Phalcon\DI\FactoryDefault();
$selection = new \Phalcon\Forms\Element\Select("selection");
$selection->addOption(array('id'=>'1','value'=>'Apple'));
$selection->addOption(array('2'=>'Orange'));
echo $selection->render(array('multiple'=>'yes')), PHP_EOL;
?>
--EXPECT--
<select id="selection" name="selection" multiple="yes">
	<option value="2">Orange</option>
	<option value="id">1</option>
	<option value="value">Apple</option>
</select>
