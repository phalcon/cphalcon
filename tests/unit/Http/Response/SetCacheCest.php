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

namespace Phalcon\Tests\Unit\Http\Response;

use DateTime;
use DateTimeZone;
use Phalcon\Tests\Unit\Http\Helper\HttpBase;
use UnitTester;

class SetCacheCest extends HttpBase
{
    /**
     * Tests setCache
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2015-07-14
     */
    public function testHttpResponseSetCache(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $expiry = new DateTime();

        $expiry->setTimezone(
            new DateTimeZone('UTC')
        );

        $expiry->modify('+60 minutes');

        $response->setCache(60);

        $actual = $response->getHeaders();
        $I->assertEquals(
            $expiry->format('D, d M Y H:i:s') . ' GMT',
            $actual->get('Expires')
        );
        $I->assertEquals(
            'max-age=3600',
            $actual->get('Cache-Control')
        );
    }
}
