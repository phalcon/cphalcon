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

namespace Phalcon\Tests\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

class GetAttributeCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getAttribute()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-11
     */
    public function httpMessageServerRequestGetAttribute(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getAttribute()');

        $request = (new ServerRequest())
            ->withAttribute('one', 'two')
            ->withAttribute('three', 'four')
        ;

        $I->assertEquals(
            'two',
            $request->getAttribute('one')
        );
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getAttribute() - unknown
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-11
     */
    public function httpMessageServerRequestGetAttributeUnknown(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getAttribute() - unknown');

        $request = (new ServerRequest())
            ->withAttribute('one', 'two')
            ->withAttribute('three', 'four')
        ;

        $I->assertEquals(
            '',
            $request->getAttribute('unknown')
        );
    }
}
