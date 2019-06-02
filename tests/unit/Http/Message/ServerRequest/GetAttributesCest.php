<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

class GetAttributesCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getAttributes()
     *
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
