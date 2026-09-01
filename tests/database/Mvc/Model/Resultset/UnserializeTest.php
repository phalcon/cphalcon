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

namespace Phalcon\Tests\Database\Mvc\Model\Resultset;

use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class UnserializeTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->setDiService('phpSerializer');
        $this->seedResultsetFixture();
    }

    /**
     * A serialise/unserialise round-trip rebuilds an equivalent resultset.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetUnserialize(): void
    {
        $original = $this->getResultset('simple');

        $restored = new Simple(null, null, null);
        $restored->unserialize($original->serialize());

        $this->assertCount(3, $restored);
        $this->assertEquals($original->toArray(), $restored->toArray());
    }
}
