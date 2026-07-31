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

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Responder\Redirect :: url()/status()
     */
    public function testAdrResponderRedirectConstruct(): void
    {
        $redirect = new Redirect('/home', 301);

        $this->assertSame('/home', $redirect->url());
        $this->assertSame(301, $redirect->status());

        $this->assertSame(302, (new Redirect('/x'))->status());
    }
}
