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

namespace Phalcon\Tests\Unit\ADR\Responder\Redirect;

use Phalcon\ADR\Responder\Redirect;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class NamedConstructorsTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Responder\Redirect :: permanent()/temporary()/seeOther()
     */
    public function testAdrResponderRedirectNamedConstructors(): void
    {
        $this->assertSame(301, Redirect::permanent('/a')->status());
        $this->assertSame(302, Redirect::temporary('/a')->status());
        $this->assertSame(303, Redirect::seeOther('/a')->status());

        $this->assertSame('/a', Redirect::permanent('/a')->url());
    }
}
