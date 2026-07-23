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

namespace Phalcon\Tests\Unit\ADR\Input\Input;

use Phalcon\ADR\Input\Input;
use Phalcon\Http\Request;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class FromRequestTest extends AbstractUnitTestCase
{

    /**
     * Unit Tests Phalcon\ADR\Input\Input :: fromRequest() - a form post is not
     * decoded as JSON
     */
    public function testAdrInputInputFromRequestFormPostIsNotJson(): void
    {
        $_SERVER['CONTENT_TYPE'] = 'application/x-www-form-urlencoded';
        $_POST                   = ['email' => 'sarah.connor@skynet.dev'];

        $input = Input::fromRequest(new Request());

        $this->assertSame('sarah.connor@skynet.dev', $input->get('email'));

        unset($_SERVER['CONTENT_TYPE']);
        $_POST = [];
    }
    /**
     * Unit Tests Phalcon\ADR\Input\Input :: fromRequest() merges route attributes
     */
    public function testAdrInputInputFromRequestMergesAttributes(): void
    {
        $request = new Request();
        $request->getAttributes()->set('id', 42);

        $input = Input::fromRequest($request);

        $this->assertSame(42, $input->get('id'));
    }
}
