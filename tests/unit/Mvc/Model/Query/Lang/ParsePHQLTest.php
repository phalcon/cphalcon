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

namespace Phalcon\Tests\Unit\Mvc\Model\Query\Lang;

use Phalcon\Mvc\Model\Query\Lang;
use Phalcon\Tests\AbstractUnitTestCase;

final class ParsePHQLTest extends AbstractUnitTestCase
{
    /**
     * Tests that two PHQL strings which previously collided under
     * zend_inline_hash_func produce distinct AST representations.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     * @issue  https://github.com/phalcon/cphalcon/issues/14791
     */
    public function testMvcModelQueryLangParsePHQLCacheCollision(): void
    {
        $phql1 = "SELECT [TagMe\Modules\Identity\Infrastructure\User\Model\Elasticsearch\Users].* "
               . "FROM [TagMe\Modules\Identity\Infrastructure\User\Model\Elasticsearch\Users] "
               . "WHERE _id = 'GcbN9FIoI8IC3LqBIuCu50AC02TpI8ruKOjyzd1fqOCuna' LIMIT :APL0:";

        $phql2 = "SELECT [TagMe\Modules\Identity\Infrastructure\User\Model\Elasticsearch\Users].* "
               . "FROM [TagMe\Modules\Identity\Infrastructure\User\Model\Elasticsearch\Users] "
               . "WHERE _id = 'GcbN9FIoI8IC3LpcIuCu50AC02TpI8ruKOjyzd1fqOCuna' LIMIT :APL0:";

        $ast1 = Lang::parsePHQL($phql1);
        $ast2 = Lang::parsePHQL($phql2);

        $this->assertNotSame($ast1, $ast2);
    }
}