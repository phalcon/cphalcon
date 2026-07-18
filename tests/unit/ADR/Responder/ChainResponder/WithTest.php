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

namespace Phalcon\Tests\Unit\ADR\Responder\ChainResponder;

use Phalcon\ADR\Responder\ChainResponder;
use Phalcon\ADR\Responder\StatusResponder;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class WithTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Responder\ChainResponder :: with()
     */
    public function testAdrResponderChainResponderWith(): void
    {
        $chain = new ChainResponder();
        $new   = $chain->with(new StatusResponder());

        $this->assertNotSame($chain, $new);
        $this->assertInstanceOf(ChainResponder::class, $new);
    }
}
