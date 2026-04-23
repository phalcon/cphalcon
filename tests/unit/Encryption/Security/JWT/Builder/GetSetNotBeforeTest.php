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
use Phalcon\Encryption\Security\JWT\Exceptions\ValidatorException;
use Phalcon\Encryption\Security\JWT\Signer\Hmac;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetNotBeforeTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTBuilderGetSetNotBefore(): void
    {
        $signer  = new Hmac();
        $builder = new Builder($signer);

        $this->assertNull($builder->getNotBefore());

        $return = $builder->setNotBefore(4);
        $this->assertInstanceOf(Builder::class, $return);

        $this->assertSame(4, $builder->getNotBefore());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTBuilderSetNotBefore(): void
    {
        $this->expectException(ValidatorException::class);
        $this->expectExceptionMessage("Invalid Not Before");

        $signer  = new Hmac();
        $builder = new Builder($signer);
        $future  = strtotime("now") + 1000;
        $builder->setNotBefore($future);
    }
}
