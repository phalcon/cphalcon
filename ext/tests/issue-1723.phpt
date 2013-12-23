--TEST--
email_field() Volt function doesn't work properly in case of a placeholder parameter - https://github.com/phalcon/cphalcon/issues/1723
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$volt = new \Phalcon\Mvc\View\Engine\Volt\Compiler();
echo $volt->compileString('{{ email_field("email", "placeholder": "E-mail") }}' . PHP_EOL . '{{ password_field("password", "placeholder": "Password") }}' . PHP_EOL);
?>
--EXPECT--
<?php echo $this->tag->emailField(array('email', 'placeholder' => 'E-mail')); ?>
<?php echo $this->tag->passwordField(array('password', 'placeholder' => 'Password')); ?>
