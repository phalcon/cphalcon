<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Dispatcher\Fake;

use Phalcon\Cache\Adapter\AdapterInterface as CacheAdapterInterface;
use Phalcon\Mvc\Model\BinderInterface;

class FakeModelBinder implements BinderInterface
{
    private ?CacheAdapterInterface $cache = null;

    /**
     * @param mixed       $handler
     * @param array       $params
     * @param string      $cacheKey
     * @param string|null $methodName
     *
     * @return array
     */
    public function bindToHandler(
        $handler,
        array $params,
        string $cacheKey,
        string $methodName = null
    ): array {
        return $params;
    }

    /**
     * @return array
     */
    public function getBoundModels(): array
    {
        return [];
    }

    /**
     * @return CacheAdapterInterface
     */
    public function getCache(): CacheAdapterInterface
    {
        return $this->cache;
    }

    /**
     * @param CacheAdapterInterface $cache
     *
     * @return BinderInterface
     */
    public function setCache(CacheAdapterInterface $cache): BinderInterface
    {
        $this->cache = $cache;

        return $this;
    }
}
