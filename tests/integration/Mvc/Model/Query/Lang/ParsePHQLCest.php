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

namespace Phalcon\Test\Integration\Mvc\Model\Query\Lang;

use IntegrationTester;

/**
 * Class ParsePHQLCest
 */
class ParsePHQLCest
{
    /**
     * Tests Phalcon\Mvc\Model\Query\Lang :: parsePHQL()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelQueryLangParsePHQL(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Lang - parsePHQL()');
        $I->skipTest('Need implementation');
    }

    public function testPhqlCollision(IntegrationTester $I)
    {
        $ast1 = Phalcon\Mvc\Model\Query\Lang::parsePHQL("SELECT [TagMe\Modules\Identity\Infrastructure\User\Model\Elasticsearch\Users].* FROM [TagMe\Modules\Identity\Infrastructure\User\Model\Elasticsearch\Users] WHERE _id = 'GcbN9FIoI8IC3LqBIuCu50AC02TpI8ruKOjyzd1fqOCuna' LIMIT :APL0:");
        $ast2 = Phalcon\Mvc\Model\Query\Lang::parsePHQL("SELECT [TagMe\Modules\Identity\Infrastructure\User\Model\Elasticsearch\Users].* FROM [TagMe\Modules\Identity\Infrastructure\User\Model\Elasticsearch\Users] WHERE _id = 'GcbN9FIoI8IC3LpcIuCu50AC02TpI8ruKOjyzd1fqOCuna' LIMIT :APL0:");
        $I->assertNotSame($ast1, $ast2);
    }
}
