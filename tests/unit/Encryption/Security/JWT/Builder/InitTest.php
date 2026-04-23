<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Builder;

use Phalcon\Encryption\Security\JWT\Builder;
use Phalcon\Encryption\Security\JWT\Signer\Hmac;
use Phalcon\Tests\AbstractUnitTestCase;

final class InitTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTBuilderInit(): void
    {
        $signer  = new Hmac();
        $builder = new Builder($signer);

        $builder->setSubject('abcdef');

        $expected = 'abcdef';
        $actual   = $builder->getSubject();
        $this->assertSame($expected, $actual);

        $builder->init();

        $this->assertNull($builder->getSubject());
    }
}
