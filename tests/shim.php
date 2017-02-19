<?php
/**
 * Phalcon Framework
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

if (!function_exists('xcache_get') && function_exists('apc_fetch')) {
    function xcache_get($key)
    {
        $ok = false;
        $result = apc_fetch($key, $ok);

        return $ok ? $result : null;
    }

    function xcache_inc($key, $step = 1)
    {
        $ok = false;
        $result = apc_inc($key, $step, $ok);

        return $ok ? $result : false;
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

    function xcache_emulation()
    {
    }
}

if (!function_exists('env')) {
    function env($key, $default = null)
    {
        if (defined($key)) {
            return constant($key);
        }

        return getenv($key) ?: $default;
    }
}
