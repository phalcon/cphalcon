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

namespace Phalcon\Tests\Unit\Translate\Adapter\Gettext;

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Translate\Fake\TranslateGettextHelperTrait;
use Phalcon\Tests\Unit\Translate\Fake\TranslateGettextTrait;

final class TTest extends AbstractUnitTestCase
{
    use TranslateGettextHelperTrait;
    use TranslateGettextTrait;

    /**
     * @return string
     */
    protected function func(): string
    {

        return 't';
    }
}
