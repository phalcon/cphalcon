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

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

class GetAttributesCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getAttributes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-11
     */
    public function httpMessageServerRequestGetAttributes(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getAttributes()');

        $request = (new ServerRequest())
            ->withAttribute('one', 'two')
            ->withAttribute('three', 'four')
        ;

        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];

        $I->assertEquals(
            $expected,
            $request->getAttributes()
        );
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getAttributes() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-11
     */
    public function httpMessageServerRequestGetAttributesEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getAttributes() - empty');

        $request = new ServerRequest();

        $I->assertEmpty(
            $request->getAttributes()
        );
    }
}
