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

use Phalcon\Cache\Backend\File;
use Phalcon\Cache\Frontend\Data;
use function cacheFolder;

/**
 * Trait FileTrait
 *
 * @package Phalcon\Test\Fixtures\Traits\Cache
 */
trait FileTrait
{
    /**
     * @var null|File
     */
    protected $cache = null;

    public function _before()
    {
        $frontCache  = new Data();
        $this->cache = new File(
            $frontCache,
            [
                'cacheDir' => cacheFolder(),
            ]
        );
    }
}
