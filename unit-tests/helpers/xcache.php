<?php

if (!function_exists('xcache_get') && function_exists('apc_fetch')) :

function xcache_get($key)
{
	$ok = false;
	$result = apc_fetch($key, $ok);
	return $ok ? $result : null;
}

function xcache_set($key, $value, $ttl = 0)
{
	return apc_store($key, $value, $ttl);
}

function xcache_isset($key)
{
	return apc_exists($key);
}

function xcache_unset($key)
{
	return apc_delete($key);
}

function xcache_emulation() {}

endif;
