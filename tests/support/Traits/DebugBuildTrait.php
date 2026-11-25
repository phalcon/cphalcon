<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Traits;

use const ZEND_DEBUG_BUILD;

trait DebugBuildTrait
{
    /**
     * Skips the test on a PHP debug build. A debug build checks the return
     * type of each internal function and stops with a fatal error. Zephir
     * does not check the return types, and a method can return null for an
     * object type that is not nullable (fixed in Zephir v7).
     */
    private function skipOnDebugBuild(): void
    {
        if (ZEND_DEBUG_BUILD) {
            $this->markTestSkipped(
                'A PHP debug build stops at a return type that Zephir does not check'
            );
        }
    }
}
