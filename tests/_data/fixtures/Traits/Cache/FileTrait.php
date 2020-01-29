<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits\Cache;

use Phalcon\Cache\Backend\File;
use Phalcon\Cache\Frontend\Data;

use function cacheDir;

trait FileTrait
{
    /**
     * @var null|File
     */
    protected $cache = null;

    public function _before()
    {
        $frontCache = new Data();

        $this->cache = new File(
            $frontCache,
            [
                'storageDir' => cacheDir(),
            ]
        );
    }
}
