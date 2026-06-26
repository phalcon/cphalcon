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

namespace Phalcon\Tests\Unit\Mvc\Model\Hydration;

use Phalcon\Mvc\Model\Hydration\CaseInsensitiveColumnMap;
use Phalcon\Tests\AbstractUnitTestCase;

final class CaseInsensitiveColumnMapTest extends AbstractUnitTestCase
{
    public function testResolvesCaseInsensitiveKey(): void
    {
        $columnMap = ['Inv_Id' => 'id', 'Inv_Title' => 'title'];

        $this->assertSame(
            'Inv_Id',
            CaseInsensitiveColumnMap::caseInsensitiveColumnMap($columnMap, 'inv_id')
        );
    }

    public function testReturnsKeyUnchangedWhenNoMatch(): void
    {
        $this->assertSame(
            'missing',
            CaseInsensitiveColumnMap::caseInsensitiveColumnMap(['a' => 'b'], 'missing')
        );
    }
}
