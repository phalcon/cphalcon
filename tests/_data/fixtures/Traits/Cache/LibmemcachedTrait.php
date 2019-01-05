<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits\Cache;

use Phalcon\Cache\Backend\Libmemcached;
use Phalcon\Cache\FrontendInterface;
/**
 * Trait FileTrait
 *
 * @package Phalcon\Test\Fixtures\Traits\Cache
 */
trait LibmemcachedTrait
{
    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('memcached');
    }

    protected function getCache(FrontendInterface $frontend, $config = [])
    {
        $config = array_merge($config, [
            'client'  => [],
            'servers' => [
                [
                    'host'   => env('DATA_MEMCACHED_HOST', '127.0.0.1'),
                    'port'   => env('DATA_MEMCACHED_PORT', 11211),
                    'weight' => env('DATA_MEMCACHED_WEIGHT', 0),
                ],
            ],
        ]);

        return new Libmemcached($frontend, $config);
    }

    protected function getDataCache($statsKey = null, $ttl = 20)
    {
        $config = [];
        if ($statsKey !== null) {
            $config['statsKey'] = $statsKey;
        }

        return $this->getCache(new Data(['lifetime' => $ttl]), $config);
    }

    protected function getOutputCache($ttl = 0)
    {
        return $this->getCache(new Output(['lifetime' => $ttl]));
    }
}
