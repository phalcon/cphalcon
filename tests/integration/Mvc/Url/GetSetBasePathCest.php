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

namespace Phalcon\Tests\Integration\Mvc\Url;

use IntegrationTester;
use Phalcon\Mvc\Url;

class GetSetBasePathCest
{
    /**
     * Tests Phalcon\Mvc\Url :: getBasePath()/setBasePath()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcUrlGetSetBasePath(IntegrationTester $I)
    {
        $I->wantToTest('Url - getBasePath()/setBasePath()');
        $url = new Url();

        $path = '/en/team';
        $url->setBasePath($path);

        $expected = $path;
        $actual   = $url->getBasePath();
        $I->assertEquals($expected, $actual);
    }
}
