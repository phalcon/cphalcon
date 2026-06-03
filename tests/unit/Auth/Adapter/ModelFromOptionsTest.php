<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Auth\Adapter;

use Phalcon\Auth\Adapter\Model;
use Phalcon\Auth\Exception;
use Phalcon\Encryption\Security;
use Phalcon\Tests\AbstractUnitTestCase;

final class ModelFromOptionsTest extends AbstractUnitTestCase
{
    private Security $security;

    protected function setUp(): void
    {
        $this->security = new Security();
    }

    public function testFromOptionsAppliesCustomIdColumn(): void
    {
        $adapter = Model::fromOptions(
            $this->security,
            [
                'model'    => 'App\\Models\\User',
                'idColumn' => 'user_id',
            ]
        );

        $this->assertSame('user_id', $adapter->getConfig()->getIdColumn());
    }

    public function testFromOptionsBuildsModelWithModelClass(): void
    {
        $adapter = Model::fromOptions(
            $this->security,
            ['model' => 'App\\Models\\User']
        );

        $this->assertInstanceOf(Model::class, $adapter);
    }

    public function testFromOptionsThrowsWhenModelMissing(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/model adapter/');

        Model::fromOptions($this->security, []);
    }
}
