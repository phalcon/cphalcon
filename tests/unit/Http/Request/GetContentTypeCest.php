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

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class GetContentTypeCest extends HttpBase
{
    public function testHttpRequestContentType(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $this->setServerVar('CONTENT_TYPE', 'application/xhtml+xml');

        $I->assertEquals(
            'application/xhtml+xml',
            $request->getContentType()
        );

        $this->unsetServerVar('CONTENT_TYPE');
    }
}
