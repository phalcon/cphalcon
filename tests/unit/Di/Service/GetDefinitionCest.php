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

namespace Phalcon\Tests\Unit\Di\Service;

use Phalcon\Di\Service;
use UnitTester;

class GetDefinitionCest
{
    /**
     * Tests Phalcon\Di\Service :: getDefinition()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-12
     */
    public function diServiceGetDefinition(UnitTester $I)
    {
        $I->wantToTest('Di\Service - getDefinition()');

        $service = new Service(
            'some-service',
            false
        );

        $I->assertEquals(
            'some-service',
            $service->getDefinition()
        );
    }
}
