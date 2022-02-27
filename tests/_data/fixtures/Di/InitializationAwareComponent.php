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

namespace Phalcon\Tests\Fixtures\Di;

use Phalcon\Di\InitializationAwareInterface;

/**
 * Class InitializationAwareComponent
 *
 * @package Phalcon\Tests\Fixtures\Di
 */
class InitializationAwareComponent implements InitializationAwareInterface
{
    private bool $initialized = false;

    public function initialize(): void
    {
        $this->initialized = true;
    }

    public function isInitialized(): bool
    {
        return $this->initialized;
    }
}
