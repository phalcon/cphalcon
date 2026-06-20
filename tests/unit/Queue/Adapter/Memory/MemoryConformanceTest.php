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

namespace Phalcon\Tests\Unit\Queue\Adapter\Memory;

use Phalcon\Contracts\Queue\Context as ContextInterface;
use Phalcon\Queue\Adapter\Memory\MemoryConnectionFactory;
use Phalcon\Tests\Unit\Queue\AbstractContextConformanceTestCase;

final class MemoryConformanceTest extends AbstractContextConformanceTestCase
{
    protected function createContext(): ContextInterface
    {
        return (new MemoryConnectionFactory())->createContext();
    }
}
