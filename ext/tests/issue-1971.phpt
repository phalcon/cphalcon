--TEST--
Phalcon\Security to support $2y$ bcrypt hashes - https://github.com/phalcon/cphalcon/issues/1971
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$s = new \Phalcon\Security();

if (CRYPT_STD_DES) {
	$s->setDefaultHash(\Phalcon\Security::CRYPT_STD_DES);
	$hash     = $s->hash('test');
	$expected = crypt('test', substr($hash, 0, 2));
	assert($hash === $expected);
}

if (CRYPT_EXT_DES) {
	$s->setDefaultHash(\Phalcon\Security::CRYPT_EXT_DES);
	$hash     = $s->hash('test');
	$expected = crypt('test', substr($hash, 0, 9));
	assert($hash === $expected);
}

if (CRYPT_MD5) {
	$s->setDefaultHash(\Phalcon\Security::CRYPT_MD5);
	$hash  = $s->hash('test');
	$parts = explode('$', $hash);
	unset($parts[3]);
	$expected = crypt('test', join('$', $parts));
	assert($hash === $expected);
}

if (CRYPT_BLOWFISH) {
	$s->setDefaultHash(\Phalcon\Security::CRYPT_BLOWFISH);
	$hash     = $s->hash('test');
	$parts    = explode('$', $hash);
	$parts[3] = substr($parts[3], 0, 22);
	$expected = crypt('test', join('$', $parts));
	assert($hash === $expected);
}

if (CRYPT_BLOWFISH && PHP_VERSION_ID >= 50307) {
	$s->setDefaultHash(\Phalcon\Security::CRYPT_BLOWFISH_X);
	$hash     = $s->hash('test');
	$parts    = explode('$', $hash);
	$parts[3] = substr($parts[3], 0, 22);
	$expected = crypt('test', join('$', $parts));
	assert($hash === $expected);
}

if (CRYPT_BLOWFISH && PHP_VERSION_ID >= 50307) {
	$s->setDefaultHash(\Phalcon\Security::CRYPT_BLOWFISH_Y);
	$hash     = $s->hash('test');
	$parts    = explode('$', $hash);
	$parts[3] = substr($parts[3], 0, 22);
	$expected = crypt('test', join('$', $parts));
	assert($hash === $expected);
}

if (CRYPT_SHA256) {
	$s->setDefaultHash(\Phalcon\Security::CRYPT_SHA256);
	$hash = $s->hash('test', 5000);
	$parts = explode('$', $hash);
	unset($parts[4]);
	$expected = crypt('test', join('$', $parts));
	assert($hash === $expected);
}

if (CRYPT_SHA512) {
	$s->setDefaultHash(\Phalcon\Security::CRYPT_SHA512);
	$hash  = $s->hash('test', 5000);
	$parts = explode('$', $hash);
	unset($parts[4]);
	$expected = crypt('test', join('$', $parts));
	assert($hash === $expected);
}
?>
--EXPECT--
