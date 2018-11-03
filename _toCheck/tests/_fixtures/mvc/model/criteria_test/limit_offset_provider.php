<?php

/**
 * Fixture for Criteria test
 *
 * @copyright (c) 2011-present Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Sergii Svyrydenko <sergey.v.svyrydenko@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc\Model
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

return [
    [-7,      null,  7                                  ],
    ["-7234", null,  7234                               ],
    ["18",    null,  18                                 ],
    ["18",    2,     ['number' => 18, 'offset' => 2]    ],
    ["-1000", -200,  ['number' => 1000, 'offset' => 200]],
    ["1000", "-200", ['number' => 1000, 'offset' => 200]],
    ["0",    "-200", null                               ],
    ["%3CMETA%20HTTP-EQUIV%3D%22refresh%22%20CONT ENT%3D%220%3Burl%3Djavascript%3Aqss%3D7%22%3E", 50, null],
];
