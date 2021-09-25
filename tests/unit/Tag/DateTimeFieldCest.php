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

namespace Phalcon\Tests\Unit\Tag;

use Phalcon\Tests\Fixtures\Helpers\TagHelper;

class DateTimeFieldCest extends TagHelper
{
    protected $function  = 'dateTimeField';
    protected $inputType = 'datetime';
}
