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

namespace Phalcon\Tests\Integration\Mvc\Model\Query\Builder;

use IntegrationTester;

/**
 * Class GetColumnsCest
 */
class GetColumnsCest
{
    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: getColumns()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelQueryBuilderGetColumns(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - getColumns()');
        $I->skipTest('Need implementation');
    }
}
