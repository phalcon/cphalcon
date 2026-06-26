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

namespace Phalcon\Tests\Unit\Mvc\Fake;

final class FakeRouter extends \Phalcon\Mvc\Router
{
    public function protectedExtractRealUri($uri)
    {
        return parent::extractRealUri($uri);
    }
}
