<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

class Memcached
{
    const OPT_COMPRESSION = -1001;
    const OPT_COMPRESSION_TYPE = -1004;
    const OPT_PREFIX_KEY = -1002;
    const OPT_SERIALIZER = -1003;
    const OPT_HASH = 2;
    const OPT_DISTRIBUTION = 9;
    const OPT_LIBKETAMA_COMPATIBLE = 16;
    const OPT_LIBKETAMA_HASH = 17;
    const OPT_TCP_KEEPALIVE = 32;
    const OPT_BUFFER_WRITES = 10;
    const OPT_BINARY_PROTOCOL = 18;
    const OPT_NO_BLOCK = 0;
    const OPT_TCP_NODELAY = 1;
    const OPT_SOCKET_SEND_SIZE = 4;
    const OPT_SOCKET_RECV_SIZE = 5;
    const OPT_CONNECT_TIMEOUT = 14;
    const OPT_RETRY_TIMEOUT = 15;
    const OPT_SEND_TIMEOUT = 19;
    const OPT_RECV_TIMEOUT = 20;
    const OPT_POLL_TIMEOUT = 8;
    const OPT_CACHE_LOOKUPS = 6;

    const HAVE_IGBINARY = 0;
    const HAVE_JSON = 0;
    const HAVE_SESSION = 1;
    const HAVE_SASL = 0;

    const HASH_DEFAULT = 0;
    const HASH_MD5 = 1;
    const HASH_CRC = 2;
    const HASH_FNV1_64 = 3;
    const HASH_FNV1A_64 = 4;
    const HASH_FNV1_32 = 5;
    const HASH_FNV1A_32 = 6;
    const HASH_HSIEH = 7;
    const HASH_MURMUR = 8;

    const DISTRIBUTION_MODULA = 0;
    const DISTRIBUTION_CONSISTENT = 1;
    const DISTRIBUTION_VIRTUAL_BUCKET = 6;
    const OPT_SERVER_FAILURE_LIMIT = 21;
    const OPT_AUTO_EJECT_HOSTS = 28;
    const OPT_HASH_WITH_PREFIX_KEY = 25;
    const OPT_NOREPLY = 26;
    const OPT_SORT_HOSTS = 12;
    const OPT_VERIFY_KEY = 13;
    const OPT_USE_UDP = 27;
    const OPT_NUMBER_OF_REPLICAS = 29;
    const OPT_RANDOMIZE_REPLICA_READ = 30;
    const OPT_REMOVE_FAILED_SERVERS = 35;

    const RES_SUCCESS = 0;
    const RES_FAILURE = 1;
    const RES_HOST_LOOKUP_FAILURE = 2;
    const RES_UNKNOWN_READ_FAILURE = 7;
    const RES_PROTOCOL_ERROR = 8;

    const RES_CLIENT_ERROR = 9;
    const RES_SERVER_ERROR = 10;
    const RES_WRITE_FAILURE = 5;

    const RES_DATA_EXISTS = 12;
    const RES_NOTSTORED = 14;
    const RES_NOTFOUND = 16;
    const RES_PARTIAL_READ = 18;
    const RES_SOME_ERRORS = 19;
    const RES_NO_SERVERS = 20;
    const RES_END = 21;
    const RES_ERRNO = 26;
    const RES_BUFFERED = 32;
    const RES_TIMEOUT = 31;
    const RES_BAD_KEY_PROVIDED = 33;
    const RES_STORED = 15;
    const RES_DELETED = 22;
    const RES_STAT = 24;
    const RES_ITEM = 25;
    const RES_NOT_SUPPORTED = 28;
    const RES_FETCH_NOTFINISHED = 30;
    const RES_SERVER_MARKED_DEAD = 35;
    const RES_UNKNOWN_STAT_KEY = 36;
    const RES_INVALID_HOST_PROTOCOL = 34;
    const RES_MEMORY_ALLOCATION_FAILURE = 17;
    const RES_CONNECTION_SOCKET_CREATE_FAILURE = 11;
    const RES_PAYLOAD_FAILURE = -1001;

    const SERIALIZER_PHP = 1;
    const SERIALIZER_IGBINARY = 2;
    const SERIALIZER_JSON = 3;
    const SERIALIZER_JSON_ARRAY = 4;

    const COMPRESSION_FASTLZ = 2;
    const COMPRESSION_ZLIB = 1;

    const GET_PRESERVE_ORDER = 1;
    const GET_ERROR_RETURN_VALUE = false;

    /**
     * @see http://php.net/manual/en/memcached.construct.php
     *
     * @param string $persistent_id
     */
    public function __construct($persistent_id)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.getresultcode.php
     *
     * @return int
     */
    public function getResultCode()
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.getresultmessage.php
     *
     * @return string
     */
    public function getResultMessage()
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.get.php
     *
     * @param string   $key
     * @param callable $cache_cb
     * @param float    $cas_token
     *
     * @return mixed
     */
    public function get($key, callable $cache_cb = null, &$cas_token = null)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.getbykey.php
     *
     * @param string   $server_key
     * @param string   $key
     * @param callable $cache_cb
     * @param float    $cas_token
     *
     * @return mixed
     */
    public function getByKey($server_key, $key, callable $cache_cb = null, &$cas_token = null)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.getmulti.php
     *
     * @param array $keys
     * @param array $cas_tokens
     * @param int   $flags
     *
     * @return mixed
     */
    public function getMulti(array $keys, array &$cas_tokens = null, $flags = null)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.getmultibykey.php
     *
     * @param string $server_key
     * @param array  $keys
     * @param string $cas_tokens
     * @param int    $flags
     *
     * @return array
     */
    public function getMultiByKey($server_key, array $keys, &$cas_tokens = null, $flags = null)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.getdelayed.php
     *
     * @param array    $keys
     * @param bool     $with_cas
     * @param callable $value_cb
     *
     * @return bool
     */
    public function getDelayed(array $keys, $with_cas = null, callable $value_cb = null)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.getdelayedbykey.php
     *
     * @param string   $server_key
     * @param array    $keys
     * @param bool     $with_cas
     * @param callable $value_cb
     *
     * @return bool
     */
    public function getDelayedByKey($server_key, array $keys, $with_cas = null, callable $value_cb = null)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.fetch.php
     *
     * @return array
     */
    public function fetch()
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.fetchall.php
     *
     * @return array
     */
    public function fetchAll()
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.set.php
     *
     * @param string $key
     * @param mixed  $value
     * @param int    $expiration
     *
     * @return bool
     */
    public function set($key, $value, $expiration = null)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.setbykey.php
     *
     * @param string $server_key
     * @param string $key
     * @param mixed  $value
     * @param int    $expiration
     *
     * @return bool
     */
    public function setByKey($server_key, $key, $value, $expiration = null)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.touch.php
     *
     * @param string $key
     * @param int    $expiration
     *
     * @return bool
     */
    public function touch($key, $expiration)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.touchbykey.php
     *
     * @param string $server_key
     * @param string $key
     * @param int    $expiration
     *
     * @return bool
     */
    public function touchByKey($server_key, $key, $expiration)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.setmulti.php
     *
     * @param array $items
     * @param int   $expiration
     *
     * @return bool
     */
    public function setMulti(array $items, $expiration = null)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.setmultibykey.php
     *
     * @param string $server_key
     * @param array  $items
     * @param int    $expiration
     *
     * @return bool
     */
    public function setMultiByKey($server_key, array $items, $expiration = null)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.cas.php
     *
     * @param float  $cas_token
     * @param string $key
     * @param mixed  $value
     * @param int    $expiration
     *
     * @return bool
     */
    public function cas($cas_token, $key, $value, $expiration = null)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.casbykey.php
     *
     * @param float  $cas_token
     * @param string $server_key
     * @param string $key
     * @param mixed  $value
     * @param int    $expiration
     *
     * @return bool
     */
    public function casByKey($cas_token, $server_key, $key, $value, $expiration = null)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.add.php
     *
     * @param string $key
     * @param mixed  $value
     * @param int    $expiration
     *
     * @return bool
     */
    public function add($key, $value, $expiration = null)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.addbykey.php
     *
     * @param string $server_key
     * @param string $key
     * @param mixed  $value
     * @param int    $expiration
     *
     * @return bool
     */
    public function addByKey($server_key, $key, $value, $expiration = null)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.append.php
     *
     * @param string $key
     * @param string $value
     *
     * @return bool
     */
    public function append($key, $value)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.appendbykey.php
     *
     * @param string $server_key
     * @param string $key
     * @param string $value
     *
     * @return bool
     */
    public function appendByKey($server_key, $key, $value)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.prepend.php
     *
     * @param string $key
     * @param string $value
     *
     * @return bool
     */
    public function prepend($key, $value)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.prependbykey.php
     *
     * @param string $server_key
     * @param string $key
     * @param string $value
     *
     * @return bool
     */
    public function prependByKey($server_key, $key, $value)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.replace.php
     *
     * @param string $key
     * @param mixed  $value
     * @param int    $expiration
     *
     * @return bool
     */
    public function replace($key, $value, $expiration = null)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.replacebykey.php
     *
     * @param string $server_key
     * @param string $key
     * @param mixed  $value
     * @param int    $expiration
     *
     * @return bool
     */
    public function replaceByKey($server_key, $key, $value, $expiration = null)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.delete.php
     *
     * @param string $key
     * @param int    $time
     *
     * @return bool
     */
    public function delete($key, $time = 0)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.deletemulti.php
     *
     * @param array $keys
     * @param int   $time
     *
     * @return bool
     */
    public function deleteMulti(array $keys, $time = 0)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.deletebykey.php
     *
     * @param string $server_key
     * @param string $key
     * @param int    $time
     *
     * @return bool
     */
    public function deleteByKey($server_key, $key, $time = 0)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.deletemultibykey.php
     *
     * @param string $server_key
     * @param array  $keys
     * @param int    $time
     *
     * @return bool
     */
    public function deleteMultiByKey($server_key, array $keys, $time = 0)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.increment.php
     *
     * @param string $key
     * @param int    $offset
     * @param int    $initial_value
     * @param int    $expiry
     *
     * @return int
     */
    public function increment($key, $offset = 1, $initial_value = 0, $expiry = 0)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.decrement.php
     *
     * @param string $key
     * @param int    $offset
     * @param int    $initial_value
     * @param int    $expiry
     *
     * @return int
     */
    public function decrement($key, $offset = 1, $initial_value = 0, $expiry = 0)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.incrementbykey.php
     *
     * @param string $server_key
     * @param string $key
     * @param int    $offset
     * @param int    $initial_value
     * @param int    $expiry
     *
     * @return int
     */
    public function incrementByKey($server_key, $key, $offset = 1, $initial_value = 0, $expiry = 0)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.decrementbykey.php
     *
     * @param string $server_key
     * @param string $key
     * @param int    $offset
     * @param int    $initial_value
     * @param int    $expiry
     *
     * @return int
     */
    public function decrementByKey($server_key, $key, $offset = 1, $initial_value = 0, $expiry = 0)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.addserver.php
     *
     * @param string $host
     * @param int    $port
     * @param int    $weight
     *
     * @return bool
     */
    public function addServer($host, $port, $weight = 0)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.addservers.php
     *
     * @param array $servers
     *
     * @return bool
     */
    public function addServers(array $servers)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.getserverlist.php
     *
     * @return array
     */
    public function getServerList()
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.getserverbykey.php
     *
     * @param string $server_key
     *
     * @return array
     */
    public function getServerByKey($server_key)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.resetserverlist.php
     *
     * @return bool
     */
    public function resetServerList()
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.quit.php
     *
     * @return bool
     */
    public function quit()
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.getstats.php
     *
     * @return array
     */
    public function getStats()
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.getversion.php
     *
     * @return array
     */
    public function getVersion()
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.getallkeys.php
     *
     * @return array
     */
    public function getAllKeys()
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.flush.php
     *
     * @param int $delay
     *
     * @return bool
     */
    public function flush($delay = 0)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.getoption.php
     *
     * @param int $option
     *
     * @return mixed
     */
    public function getOption($option)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.setoption.php
     *
     * @param int   $option
     * @param mixed $value
     *
     * @return bool
     */
    public function setOption($option, $value)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.setoptions.php
     *
     * @param array $options
     *
     * @return bool
     */
    public function setOptions(array $options)
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.ispersistent.php
     *
     * @return bool
     */
    public function isPersistent()
    {
    }

    /**
     * @see http://php.net/manual/en/memcached.ispristine.php
     *
     * @return bool
     */
    public function isPristine()
    {
    }

    /**
     * @see https://www.php.net/manual/en/memcached.setsaslauthdata.php
     */
    public function setSaslAuthData(string $username, string $password): void
    {
    }
}
