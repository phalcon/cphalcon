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

namespace Phalcon\Test\Integration\Mvc\Model\MetaData\Redis;

use IntegrationTester;

/**
 * Class GetNotNullAttributesCest
 */
class GetNotNullAttributesCest
{
    /**
     * Tests Phalcon\Mvc\Model\MetaData\Redis :: getNotNullAttributes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelMetadataRedisGetNotNullAttributes(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData\Redis - getNotNullAttributes()');
        $I->skipTest('Need implementation');
    }
}
